# EL

Code for the [SparkFun EL Wire Sequencer](https://www.sparkfun.com/products/12781). See [here](https://github.com/sparkfun/EL_Sequencer/) for SparkFun's example code.

## Setup

This readme assumes your sequencer is hooked up and functional.

- Install Arduino IDE
- Install drivers
- Clone this repo
- Upload code to your sequencer

### Install Arduino IDE

[Sparkfun Arduino IDE Installation Guide](https://learn.sparkfun.com/tutorials/installing-arduino-ide)

### Install Drivers

[Sparkfun FTDI Driver Installation Guide](https://learn.sparkfun.com/tutorials/how-to-install-ftdi-drivers)

If you're not keen on reading the whole guide, skip to your OS here:

- [Windows](https://learn.sparkfun.com/tutorials/how-to-install-ftdi-drivers/windows---quick-and-easy)
- [Mac OS X](https://learn.sparkfun.com/tutorials/how-to-install-ftdi-drivers/mac)
- [Linux](https://learn.sparkfun.com/tutorials/how-to-install-ftdi-drivers/linux)

### Uploading Code from Arduino IDE

- Board: "LilyPad Arduino"
- Processor: "ATmega328"
- COM port: Whichever port the FTDI Basic appears on for your operating system. (hint: look at your port list before and after plugging in the arduino, you'll find it)

![alt text](https://cloud.githubusercontent.com/assets/8518543/25885896/e52e3606-350f-11e7-9950-630cfb8edf86.png)

For more information, see [Sparkfun's hookup guide](https://learn.sparkfun.com/tutorials/el-sequencerescudo-dos-hookup-guide#arduino-code).

## Troubleshooting

### Can't Upload Code

```
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
```

Stopgap measure: unplug FTDI, plug it back in, upload.