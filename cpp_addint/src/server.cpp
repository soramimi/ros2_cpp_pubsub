#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/add_int.hpp"
#include <memory>

void add(const std::shared_ptr<tutorial_interfaces::srv::AddInt::Request> request, std::shared_ptr<tutorial_interfaces::srv::AddInt::Response> response)
{
	response->result = request->left + request->right;

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\nleft: %d" " right: %d", request->left, request->right);
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%d]", response->result);
}

int main(int argc, char **argv)
{
	rclcpp::init(argc, argv);
	std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_int_server");
	rclcpp::Service<tutorial_interfaces::srv::AddInt>::SharedPtr service = node->create_service<tutorial_interfaces::srv::AddInt>("add_int", &add);
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add ints.");
	rclcpp::spin(node);
	rclcpp::shutdown();
}
