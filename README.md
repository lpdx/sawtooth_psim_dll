# sawtooth_psim_dll
This sawtooth wave generator was tested in PowerSim v9 64bits and its intended to overrun the issue with the element "Saw-tooth voltage source (grounded)".

The sawtooth-wave voltage generator doesn't work properly when the frequency is about 1/10 of the frequency of the simulation.

As shown in figure 1, the signal vtri_cg (blue) not always get to value of 1.
![comparativo](https://user-images.githubusercontent.com/13546280/104252965-21706e80-5452-11eb-8278-97423700fbbe.PNG)
figure 1

The FFT from both signals shows in figure 2 the correct frequency at 25kHz.
![25kHz](https://user-images.githubusercontent.com/13546280/104252984-2c2b0380-5452-11eb-9e34-29ad64706e94.PNG)
figure 2
