# Strain Gage-based Scale System Using Arduino and MATLAB

## Design Specifications

The project had two main design components. The first objective was to implement two signal conditioning circuits for the load cell. The second goal was to developed a data acquisition system with a graphical user interface (GUI) to evaluate the strain gage measure accuracy and strain gage measure calibration of each signal conditioning circuit.


#### Signal conditioning

We were asked to:

1. Use the INA121 instrumentation amplifier to conditioner the signal from the load cell.
2. Build our own instrumentation amplifier using the LM358 op amp.

#### Weight measure analysis software

3. Automate the process of taking and displaying weigh measures.
4. Demonstrate the changes in the system performance by
adjusting the parameters of the sensor signal conditioning
circuits.

As we started designing, we set additional specifications to meet:

5. Allow various interactive post signal processing, such as standard deviations and histogram.

#### Components available
1. Omega LCEB-25 load cell
2. LM328 Operational Amplifier
3. INA212 Instrumentation Amplifier
4. Arduino Uno Board
5. Adafruit SSD1306 Monochrome 1.3" 128x64 OLED
graphic display
6. PC with MATLAB and Arduino Software (IDE)

## System Overview

The block diagram for the load-cell interface is shown bellow ,
and it consists primarily of an instrumentation amplifier with gain to condition the load cell’s output signal prior to sampling by the ADC and the excitation voltage source, which in this case is the system’s 5.0V power.


![alt text][block_diagram]

[block_diagram]: https://github.com/gustavohb/strain-gage-based-scale-system/blob/master/images/block_diagram.png
