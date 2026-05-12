
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class BarcodeNode : public rclcpp::Node {
public:
    BarcodeNode() : Node("barcode_node") {
        publisher_ = this->create_publisher<std_msgs::msg::String>("/barcode", 10);
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BarcodeNode>());
    rclcpp::shutdown();
    return 0;
}
