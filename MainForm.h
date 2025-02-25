#pragma once
#include "Ball.h"
#include "random"

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
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->frame = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->BeginInit();
			this->SuspendLayout();
			// 
			// frame
			// 
			this->frame->Location = System::Drawing::Point(12, 12);
			this->frame->Name = L"frame";
			this->frame->Size = System::Drawing::Size(649, 467);
			this->frame->TabIndex = 0;
			this->frame->TabStop = false;
			this->frame->Click += gcnew System::EventHandler(this, &MainForm::frame_Click);
			this->frame->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::frame_Paint);
			this->frame->DoubleClick += gcnew System::EventHandler(this, &MainForm::frame_DoubleClick);
			this->frame->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseDown);
			this->frame->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseMove);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(673, 491);
			this->Controls->Add(this->frame);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Balls Game";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frame_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ grp = e->Graphics;
		grp->FillRectangle(% SolidBrush(Color::White), 0, 0, frame->Width, frame->Height);
		ball->draw(grp);
	}
	private: System::Void frame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			ball->setPos(e->X, e->Y);
			frame->Invalidate();
		}
	}
	private: System::Void frame_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			ball->setPos(e->X, e->Y);
			frame->Invalidate();
		}	
	}
	private: System::Void frame_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
		ball->setColor(Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb());
		frame->Invalidate();
	}
	private: void Form_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (ModifierKeys == Keys::Control) { 
			if (e->Delta > 0) {
				ball->setSize(ball->getSize() + 5);
				frame->Invalidate();
			}
			else {
				ball->setSize(ball->getSize() - 5);
				frame->Invalidate();
			}
		}
	}
	};
}
