import processing.sound.*;
import processing.serial.*;
import javax.swing.*;
import cc.arduino.*;

Arduino arduino;
SoundFile soundfile;

String arduinoSelection;
int totalPortas, escolhaPorta;

void setup() 
{
    size(640,360);
    background(255);
        
    //Load a soundfile
    soundfile = new SoundFile(this, "vibraphon.aiff");

    // These methods return useful infos about the file
    println("SFSampleRate= " + soundfile.sampleRate() + " Hz");
    println("SFSamples= " + soundfile.frames() + " samples");
    println("SFDuration= " + soundfile.duration() + " seconds");

    // Play the file in a loop
    soundfile.loop();
    
      // Prints out the available serial ports.
  String [] arduinoLista = Arduino.list();  
  JOptionPane.showMessageDialog(frame, arduinoLista, "", JOptionPane.INFORMATION_MESSAGE);
  
  //choose arduino port
  arduinoSelection = JOptionPane.showInputDialog (frame ,"", "Porta Arduino",JOptionPane.QUESTION_MESSAGE);
  
  try
  {
    if (arduinoSelection!=null || arduinoSelection!="")
    {
      escolhaPorta=Integer.parseInt(arduinoSelection);
      totalPortas = arduinoLista.length;
    }
    if (arduinoSelection!=null && escolhaPorta>=0 && escolhaPorta<arduinoLista.length)
    {
      arduino = new Arduino(this, Arduino.list()[escolhaPorta], 57600);
    }
  }
  catch(Exception e)
  {
    e.printStackTrace();
  }
}      

float valorMedido, valorMedido1, valorMedido2, valorMedido3, valorMedido4, valorMedido5;
float valorTotalMedia;

//read values from Arduino inputs
void atualizaMedicoes()
{
  //igual numero de sensores
   valorMedido=arduino.analogRead(0);
   
   //media dos valores
   valorTotalMedia = (valorMedido)/1;
}

void draw() 
{ 
  atualizaMedicoes();
  // Map mouseY from 0.2 to 1.0 for amplitude  
  soundfile.amp(map(valorTotalMedia, 0, 400, 0.2, 1.0)); 
}