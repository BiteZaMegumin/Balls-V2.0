#pragma once
#include "Ball.h"
#include "random"
#include "windows.h"

namespace BallsV20 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			MouseWheel += gcnew MouseEventHandler(this, &MainForm::Form_MouseWheel);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ frame;
	private: System::Windows::Forms::Timer^ moveTimer;
	public:
	private: System::Windows::Forms::Timer^ frameTimer;


	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->frame = (gcnew System::Windows::Forms::PictureBox());
			this->moveTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->frameTimer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->BeginInit();
			this->SuspendLayout();
			// 
			// frame
			// 
			this->frame->Location = System::Drawing::Point(16, 15);
			this->frame->Margin = System::Windows::Forms::Padding(4);
			this->frame->Name = L"frame";
			this->frame->Size = System::Drawing::Size(865, 575);
			this->frame->TabIndex = 0;
			this->frame->TabStop = false;
			this->frame->Click += gcnew System::EventHandler(this, &MainForm::frame_Tick);
			this->frame->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::frame_Paint);
			this->frame->DoubleClick += gcnew System::EventHandler(this, &MainForm::frame_DoubleClick);
			this->frame->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseDown);
			this->frame->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseMove);
			this->frame->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseUp);
			// 
			// moveTimer
			// 
			this->moveTimer->Enabled = true;
			this->moveTimer->Interval = 10;
			this->moveTimer->Tick += gcnew System::EventHandler(this, &MainForm::moveTimer_Tick);
			// 
			// frameTimer
			// 
			this->frameTimer->Enabled = true;
			this->frameTimer->Interval = 10;
			this->frameTimer->Tick += gcnew System::EventHandler(this, &MainForm::frame_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(897, 604);
			this->Controls->Add(this->frame);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Balls Game";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		int timerCheck = 0, Dx, Dy;
	private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ grp = e->Graphics;
		grp->FillRectangle(% SolidBrush(Color::White), 0, 0, frame->Width, frame->Height);
		ball->draw(grp);
	}
	private: System::Void frame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			ball->setPos(e->X, e->Y);
			Dx = e->X;
			Dy = e->Y;
			timerCheck = 0;
		}
		if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			ball->followTo(e->X, e->Y);
		}
	}
	private: System::Void frame_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			ball->setPos(e->X, e->Y);
		}	
		if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			ball->followTo(e->X, e->Y);
		}
	}
	private: System::Void frame_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
		ball->setColor(Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb());
	}
	private: void Form_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (ModifierKeys == Keys::Control) { 
			if (e->Delta > 0) {
				ball->setSize(ball->getSize() + 5);
			}
			else {
				ball->setSize(ball->getSize() - 5);
			}
		}
		else {
			int x, y;
			x = ball->getSpdX();
			y = ball->getSpdY();
			if (e->Delta > 0) {
				if (x > 0) x += 5;
				else x -= 5;
				if (y > 0) y += 5;
				else y -= 5;
				ball->setSpeed(x, y);
			}
			else {
				if (x > 0) x -= 5;
				else x += 5;
				if (y > 0) y -= 5;
				else y += 5;
				ball->setSpeed(x, y);
			}
		}
	}
	private: System::Void frame_Tick(System::Object^ sender, System::EventArgs^ e) {
		frame->Invalidate();
	}
private: System::Void moveTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	timerCheck++;
	ball->move();
	}
private: System::Void frame_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	float x = (e->X - Dx)/timerCheck , y = (e->Y - Dy) / timerCheck;
	ball->setSpeed(x, y);
}
};
}
