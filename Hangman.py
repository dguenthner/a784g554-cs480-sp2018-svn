from graphics import *


def hangman():
    #This creates new dialog box
    win = GraphWin ('Hangman', 500, 500)
    win.setBackground(color_rgb(185,199,204))

    #Display welcome
    Text(Point(250,15), "Welcome, to HANGMAN!").draw(win)
    prompt = Text(Point(250,35), "Follow the below prompts to prevent hanging yourself.").draw(win)
    
    #Draw the gallows and hangman
    beam = Line(Point(100,50),Point(400,50)).draw(win)
    noose = Line(beam.getCenter(),Point(250,100)).draw(win)
    head = Circle(Point(250,150),50).draw(win)
    neck = Line(Point(250,200),Point(250,225)).draw(win)
    ltarm = Line(Point(250,225),Point(200,250)).draw(win)
    rtarm = Line(Point(250,225),Point(300,250)).draw(win)
    body = Line(Point(250,225),Point(250,300)).draw(win)
    ltleg = Line(Point(250,300),Point(200,325)).draw(win)
    rtleg = Line(Point(250,300),Point(300,325)).draw(win)
    
    #Change prompt message
    time.sleep(3)
    prompt.undraw()
    prompt = Text(Point(250,40), "Good Luck!").draw(win)
    time.sleep(3)
    prompt.undraw()

    input1 = Entry(Point(100,450),5)
    input1.setText("")
    input1.draw(win)
    button = Text(Point(250,450), "Enter")
    button.draw(win)
    win.getMouse()

    if (input1.getText() == 'Y'):
        win.close()
    elif (input1.getText() == 'N'):
        button.undraw()    
    
