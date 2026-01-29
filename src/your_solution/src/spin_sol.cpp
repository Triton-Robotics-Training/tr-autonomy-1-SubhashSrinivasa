#include "spin_sol.h"
#include <functional>
using namespace std::chrono_literals;
int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SpinSolution>());
  rclcpp::shutdown();
  return 0;
}

//your code here
SpinSolution::SpinSolution() : Node("spinsolution") {
  // your code here
    this->pos.data.resize(2, 0.0);
    this->vel.data.resize(2, 0.0);
    subpos_ = this->create_subscription<std_msgs::msg::Float64MultiArray>(
      "/measuredpos", 10,
      std::bind(&SpinSolution::set_pos, this, std::placeholders::_1));
    subvel_ = this->create_subscription<std_msgs::msg::Float64MultiArray>(
      "/measuredvel", 10,
      std::bind(&SpinSolution::set_vel, this, std::placeholders::_1));
    timer_ = this->create_wall_timer(
      100ms, std::bind(&SpinSolution::timer_callback, this));
    pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>(
            "/predictedpos", 10);
}

void SpinSolution::set_pos(const std_msgs::msg::Float64MultiArray::SharedPtr msg) {
  RCLCPP_INFO(this->get_logger(), "Test");  
  this->pos.data = msg->data;

}
void SpinSolution::set_vel(const std_msgs::msg::Float64MultiArray::SharedPtr msg) {
  // your code here 
  this->vel.data = msg->data;
}
void SpinSolution::timer_callback() {
  // your code here
  std_msgs::msg::Float64MultiArray out_msg;
  out_msg.data.resize(2);
  out_msg.data[0] = this->pos.data[0] + this->vel.data[0] * 0.1;
  out_msg.data[1] = this->pos.data[1] + this->vel.data[1] * 0.1;
  this->pos.data = out_msg.data;
  pub_->publish(out_msg);
}

