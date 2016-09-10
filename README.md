# Strain Gage-based Scale System

This user interface for a strain gage-based scale system was written as part of a summer project at the Montana State University, Bozeman.

![screenshot](https://cloud.githubusercontent.com/assets/3193712/10882088/0afde71c-814f-11e5-9c5e-3772b41304bf.png)

The primary requeriment of the user interface was to provide real time readout of the load applied in grams.


## About

This project uses an Arduino Uno board to sample the load data and communicate with MATLAB via USB.


### What does this code do?

* Automate the process of taking and displaying weight measures.
* Demonstrate the changes in the system performance by
adjusting the parameters of the sensor signal conditioning
circuits.
* Allow various interactive post signal processing, such as standard deviations and histogram.


## License

See the [LICENSE](https://github.com/gustavohb/strain-gage-based-scale-system/blob/master/LICENSE) file for license rights and limitations (MIT).
