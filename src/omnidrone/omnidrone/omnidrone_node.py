import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


class OmnidroneTwist(Node):
    def __init__(
        self,
        node_name: str,
        *,
        context: rclpy.Context = None,
        cli_args: rclpy.List[str] = None,
        namespace: str = None,
        use_global_arguments: bool = True,
        enable_rosout: bool = True,
        start_parameter_services: bool = True,
        parameter_overrides: rclpy.List[rclpy.Parameter] = None,
        allow_undeclared_parameters: bool = False,
        automatically_declare_parameters_from_overrides: bool = False,
    ) -> None:
        super().__init__(
            node_name,
            context=context,
            cli_args=cli_args,
            namespace=namespace,
            use_global_arguments=use_global_arguments,
            enable_rosout=enable_rosout,
            start_parameter_services=start_parameter_services,
            parameter_overrides=parameter_overrides,
            allow_undeclared_parameters=allow_undeclared_parameters,
            automatically_declare_parameters_from_overrides=automatically_declare_parameters_from_overrides,
        )
        self.subscription = self.create_subscription(
            Twist, "cmd_vel", self.listener_callback, 10
        )

    def listener_callback(self, msg: Twist):
        self.get_logger().info(f"received linera velocity: x: {msg.linear.x}")


def main(args=None):
    rclpy.init(args=args)
    velocity_sub = OmnidroneTwist("omnidrone_cmd_vel")
    rclpy.spin(velocity_sub)

    velocity_sub.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
