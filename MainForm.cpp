#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#include "MainForm.h"
#include "Ball.h"
using namespace System;
using namespace System::Windows::Forms;
int main()
{
	srand((unsigned)time(NULL));
	Application::EnableVisualStyles();
	BallsV20::MainForm form;
	ball = new Ball(form.frame->Width, form.frame->Height);
	Application::Run(% form);
	delete ball;
}
