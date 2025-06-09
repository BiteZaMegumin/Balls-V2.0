#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#include "MainForm.h"
#include "Ball.h"
#include "manager.h"
using namespace System;
using namespace System::Windows::Forms;
int main()
{
	srand((unsigned)time(NULL));
	Application::EnableVisualStyles();
	BallsV20::MainForm form;
	manager = new Manager(form.frame->Width, form.frame->Height);
	Application::Run(% form);
	delete manager;
}
