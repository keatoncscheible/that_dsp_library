# That DSP Library

Welcome to That C++ DSP Library! This powerful C++ library is designed to provide a comprehensive set of tools for digital signal processing (DSP) tasks. Whether you're a seasoned DSP engineer or new to the field, this library aims to simplify the implementation of DSP algorithms and components, following best practices and software design patterns.

## Features Implemented

### Signal Processing

- **[Signal Class](include/signal.h)** The library offers a versatile `Signal` class that empowers you to work with one-dimensional signal data effortlessly. It comes equipped with essential functionalities, making common signal processing operations intuitive and efficient.

  - **Element-wise Operations:** The `Signal` class supports element-wise addition, subtraction, multiplication, and division. This allows you to manipulate signal data in a straightforward manner.

  - **Signal Initialization:** You can initialize a `Signal` with all zeros or fill it with a specific value, making it flexible for various use cases.

  - **Divide by Zero Handling:** The library intelligently handles division by zero scenarios, offering options to set results to the maximum value of the type or to zero.

- **[ControlSignal Class](include/control_signal.h)**: Extending the functionality of the `Signal` class, the `ControlSignal` class introduces additional capabilities tailored for control applications.

  - **Value Setting:** The `ControlSignal` class allows you to set all values in the signal to a specified value, simplifying the initialization of control signals.

  - **Ramping:** With the ramping functionality, you can smoothly transition the values of a `ControlSignal` from one value to another, ideal for applications that require gradual changes over time.

### Unit Testing

- **Google Test Integration:** Ensuring the reliability of your DSP components is crucial. The library provides a solid unit testing framework using Google Test. You can easily write and execute tests to verify the correctness of your implementations, promoting robust code.

## Examples

To help you get started, the library includes example files that demonstrate the core features:

- [`examples/signal_example.cpp`](examples/signal_example.cpp):</br>This example showcases how to utilize the `Signal` class for basic signal operations like addition, subtraction, multiplication, and division. It guides you through initializing signals, performing operations, and printing results.

- [`examples/control_signal_example.cpp`](examples/control_signal_example.cpp):</br>The `ControlSignal` class is highlighted in this example. It illustrates how to set values and perform ramping operations on control signals, providing insights into managing dynamic changes in control applications.

## Ongoing Development

That DSP Library is a project in active development. While the current implementation offers some tools for implementing DSP algorithms, there are continuous efforts to expand its capabilities. You can expect to see more features, improvements, and optimizations in future releases.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Feedback and Contributions

Your feedback is crucial to shaping the future of That DSP Library. I value your input and am eager to hear your thoughts on the library's current features and functionality. If you have suggestions for improvements, new features, or any ideas to enhance the usability of the library, please don't hesitate to reach out.

### How to Provide Feedback

- **Feature Requests:** If you feel that a specific DSP-related feature is missing from the library, please let me know. I'm committed to expanding the library's capabilities to better serve the needs of the DSP community.

- **Bug Reports:** If you encounter any issues while using the library, please report them. Your bug reports help to identify and address any problems, ensuring the library's reliability.

### Getting in Touch

You can contact me by [email](mailto:thatdspguy@gmail.com) or [GitHub Issues](https://github.com/keatoncscheible/that_dsp_library/issues). I welcome open discussions and collaboration to make That DSP Library even better.

### Contributing

If you're passionate about DSP and would like to contribute to the library's development, I'd be thrilled to have you on board. You can submit pull requests, contribute code, and join the discussions on GitHub. Together, we can create a powerful resource for the DSP community.

### Stay Updated

Keep an eye on the [repository](https://github.com/keatoncscheible/that_dsp_library) for updates and new releases. I'm dedicated to continuously enhancing the library and providing you with more tools to make your DSP projects a success.

Thank you for being part of That DSP Library's journey. Your support and involvement make a significant difference!