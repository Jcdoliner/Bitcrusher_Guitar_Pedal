# Bitcrusher Guitar Pedal
This is an Arduino Project that creates a PWM signal out of a guitar input to create distortion. 
You can upload the code to your personal Arduino Mega and test the circuit response.

# Wiring
Taking the source in the following picture as your guitar input, here is a simplified circuit to treat the input guitar signal
![image](https://user-images.githubusercontent.com/124648406/217666580-2610650c-3064-448b-8763-8343f3d0cc01.png)

This is connected to the Arduino analog pin A0

The output will then be passed to a filter and an amplifier that will treat the signal.The LC filter values are not specified as you can test different configurations to see what suits you best, in theory, an RC high pass filter might also work for this scenario. You might want to try running the signal without a filter but bear in mind that it will create very high noise levels.
![image](https://user-images.githubusercontent.com/124648406/217668296-38a1b26e-5e6d-4204-9dc3-cf1f5735ddfb.png)


# Final Build
![image](https://user-images.githubusercontent.com/124648406/217668589-0f5c9522-f959-4786-9be8-0aa8d881bc5b.png)



# Notes
- The output wiring is not optimal as I did not have a power supply that could provide negative voltage for the OP Amp, if you have such a system available you might want to try an Inverting Amplifier:
![Op-Amp_Inverting_Amplifier svg](https://user-images.githubusercontent.com/124648406/217669402-bc3343ae-8162-4924-8245-f1148d885feb.png)
- This code is writen for the Arduino Mega (or ELEGOO Mega for third party Arduino-like devices). 
- If your arduino has a build in Digital to analog Converter (DAC) then this is not the optimal approach for this project, as it is just as simple as passing the input signal directly to the DAC outputs (these outputs will reduce the quality of the original signal and create the desired bit distortion)
- On the following Powerpoint presentation, there is explanations about the design process and connections as well as the struggles designing this project on the arduino Mega: [Bit Crusher Pedal.pptx](https://github.com/Jcdoliner/Bitcrusher_Guitar_Pedal/files/10690522/Bit.Crusher.Pedal.pptx)
- Any feedback on the project design is appreciated!
