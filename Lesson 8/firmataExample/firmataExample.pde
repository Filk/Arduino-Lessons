import javax.swing.*;
import processing.serial.*;
import cc.arduino.*;

Arduino arduino;

String arduinoSelection;
int totalPortas, escolhaPorta;

void setup ()
{
  size (900,800);
  
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

float valorMedido;

//read values from Arduino inputs
void atualizaMedicoes()
{
    valorMedido=arduino.analogRead(0);
    println(valorMedido);
}

void draw()
{
  background(0);
  atualizaMedicoes();
  fill(255);
  ellipse(width/2,height/2,valorMedido,valorMedido);
}