int count = 1;

//left
int red_one = 11;
int green_one = 10; 
int blue_one = 9; 

//right
int red_two = 3;
int green_two = 5;
int blue_two = 6;

//not implemented yet, i'm still deciding
int on_off = 7;

//pink, purple, blue *purple is a reference
int color[3][3] = {{214, 2, 112}, {155,79,150}, {0,56,168}}; 

//pink-purple, purple-blue
float interval[2][3] = {{((color[1][0]-color[0][0])/5), ((color[1][1]-color[0][1])/5), ((color[1][2]-color[0][2])/5)}, 
                       {((color[2][0]-color[1][0])/5), ((color[2][1]-color[1][1])/5), ((color[2][2]-color[1][2])/5)}}; 

void setup() 
{
  pinMode(red_one, OUTPUT);
  pinMode(green_one, OUTPUT);
  pinMode(blue_one, OUTPUT);
  
  pinMode(red_two, OUTPUT);
  pinMode(green_two, OUTPUT);
  pinMode(blue_two, OUTPUT);
  
  pinMode(on_off, INPUT);
}

void RGB_color(int eye, int red, int green, int blue)
{
  if (eye == 1) //giraffe's left
  {
    analogWrite(red_one, red);
    analogWrite(green_one, green);
    analogWrite(blue_one, blue);
  }

  else // giraffe's right
  {
    analogWrite(red_two, red);
    analogWrite(green_two, green);
    analogWrite(blue_two, blue);
  }
}

static int pride(int count, String color)
{  
    float red, green, blue;
    
    if (color == "red")
      {
        if (count <= 5) //pink
      {
        red = color[0][0];
      }
      
      else if (count <= 10) //to purple
      {
        red = color[0][0]-((count-5)*interval[0][0]);
      }
      
      else if (count <= 15) //to blue
      {
        red = color[1][0]-((count-10)*interval[1][0]);
      }
  
      else if (count <= 20) //blue
      {
        red = color[2][0];
      }
  
      else if (count <= 25) //to purple
      {
        red = color[2][0]+((count-20)*interval[1][0]);
      }
  
      else if (count <= 30) //to pink
      {
        red = color[1][0]+((count-25)*interval[0][0]);
      }
  
      else //pink
      {
        red = color[0][0];
      }
  
      int redF = floor(red);
  
      return redF;
      }

    else if (color == "green")
    {
      if (count <= 5) //pink
      {
        green = color[0][1];
      }
      
      else if (count <= 10) //to purple
      {
        green = color[0][1]-((count-5)*interval[0][1]);
      }
      
      else if (count <= 15) //to blue
      {
        green = color[1][1]-((count-10)*interval[1][1]);
      }
  
      else if (count <= 20) //blue
      {
        green = color[2][1];
      }
  
      else if (count <= 25) //to purple
      {
        green = color[2][1]+((count-20)*interval[1][1]);
      }
  
      else if (count <= 30) //to pink
      {
        green = color[1][1]+((count-25)*interval[0][1]);
      }
  
      else //pink
      {
        green = color[0][1];
      }
  
      int greenF = floor(green);
  
      return greenF;
    }

    else if (color == "blue")
    {
      if (count <= 5) //pink
      {
        blue = color[0][2];
      }
      
      else if (count <= 10) //to purple
      {
        blue = color[0][2]-((count-5)*interval[0][2]);
      }
      
      else if (count <= 15) //to blue
      {
        blue = color[1][2]-((count-10)*interval[1][2]);
      }
  
      else if (count <= 20) //blue
      {
        blue = color[2][2];
      }
  
      else if (count <= 25) //to purple
      {
       blue = color[2][2]+((count-20)*interval[1][2]);
      }
  
      else if (count <= 30) //to pink
      {
        blue = color[1][2]+((count-25)*interval[0][2]);
      }
  
      else //pink
      {
        blue = color[0][2];
      }
  
      int blueF = floor(blue);
  
      return blueF;
    }
}

void loop() 
{
  if (count != 35)
  {
    RGB_color(1, pride(count));
    RGB_color(2, pride(count));
  }

  else
  {
    RGB_color(1, pride(count, "red"), pride(count, "green"), pride(count, "blue"));
    RGB_color(2, pride(count, "red"), pride(count, "green"), pride(count, "blue"));

    count = 5;
  }
  
  count ++;
  
  delay 1000;
}
