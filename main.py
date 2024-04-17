import RPi.GPIO as GPIO

PI = 3.141592653589793


class StepperMotor:
    def __init__(
        self,
        step_pin,
        dir_pin,
        steps_per_rev: int = 200,
        wheel_radius: float = 40 / 1000,
    ):
        self._step_pin = step_pin
        self._dir_pin = dir_pin
        self._steps_per_rev = steps_per_rev
        self._wheel_radius = wheel_radius
        GPIO.setup(self._step_pin, GPIO.OUT)
        GPIO.setup(self._dir_pin, GPIO.OUT)
        self._step_pwm = GPIO.PWM(self._step_pin, 100)

    def stop(self):
        self._step_pwm.stop()

    def start(self):
        self._step_pwm.start(50)

    def set_rpm(self, rpm):
        frequency = rpm * self._steps_per_rev * 60
        self._step_pwm.ChangeFrequence(frequency)

    def set_speed(self, speed):
        rpm = (30 * speed) / (PI * self._wheel_radius)
        self.set_rpm(rpm)


# Motor setup and usage remain the same as in the original template.

# Setup
GPIO.setmode(GPIO.BCM)  # Use Broadcom pin-numbering scheme

# Motor instances - Update pins as needed
motor1 = StepperMotor(17, 18)
motor2 = StepperMotor(22, 23)
motor3 = StepperMotor(24, 25)
motor4 = StepperMotor(27, 4)
