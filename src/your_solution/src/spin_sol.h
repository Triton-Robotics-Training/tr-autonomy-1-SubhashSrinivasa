#ifndef YOUR_SOLUTION_SRC_SPIN_SOL_H_
#define YOUR_SOLUTION_SRC_SPIN_SOL_H_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
using ArrayMsg = std_msgs::msg::Float64MultiArray;

class SpinSolution : public rclcpp::Node {
 public:
  SpinSolution();
 private:
  std_msgs::msg::Float64MultiArray pos;
  std_msgs::msg::Float64MultiArray vel;
  
  void set_pos(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
  void set_vel(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
  void timer_callback();
  rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr subpos_;
  rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr subvel_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_;
};

#endif //YOUR_SOLUTION_SRC_SPIN_SOL_H_
