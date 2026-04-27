#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist_stamped.hpp"
#include <termios.h>
#include <unistd.h>
#include <iostream>

class WASDControl : public rclcpp::Node
{
public:
    WASDControl() : Node("wasd_control")
    {
        pub_ = create_publisher<geometry_msgs::msg::TwistStamped>("/cmd_vel", 10);

        RCLCPP_INFO(get_logger(), "WASD Control Started");
        RCLCPP_INFO(get_logger(), "Use W/A/S/D to control, Q to quit");

        run();
    }

private:
    rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr pub_;

    char getKey()
    {
        struct termios oldt, newt;
        char c;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        read(STDIN_FILENO, &c, 1);

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return c;
    }

    void run()
    {
        while (rclcpp::ok())
        {
            char key = getKey();

            geometry_msgs::msg::TwistStamped cmd;
            cmd.header.stamp = now();

            switch (key)
            {
                case 'w':
                    cmd.twist.linear.x = 0.15;
                    break;

                case 'a':
                    cmd.twist.angular.z = 0.5;
                    break;

                case 'd':
                    cmd.twist.angular.z = -0.5;
                    break;

                case 's':
                    cmd.twist.linear.x = 0.0;
                    cmd.twist.angular.z = 0.0;
                    break;

                case 'q':
                    RCLCPP_INFO(get_logger(), "Exiting...");
                    return;

                default:
                    continue;
            }

            pub_->publish(cmd);
        }
    }
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<WASDControl>());
    rclcpp::shutdown();
    return 0;
}
