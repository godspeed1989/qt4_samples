#include "style.h"

style::style()
{
	setWindowTitle("Style");

	this->left();
	this->right();

	QHBoxLayout* main = new QHBoxLayout();
	main->setMargin(8);
	main->setSpacing(5);
	main->addWidget(this->leftFrame);
	main->addWidget(this->rightFrame);
	setLayout(main);
}

void style::left()
{	
	leftFrame = new QFrame();
	leftFrame->setFrameStyle(QFrame::Panel|QFrame::Sunken);//'Sunken'下沉 
	
	//---"Combo Box" & "Button"---//
	QComboBox* combo = new QComboBox();
	combo->addItems(QStyleFactory::keys());
	QPushButton* button = new QPushButton("&B");
	//-----"HBox Layout"-----//
	QHBoxLayout* hbox = new QHBoxLayout();
	hbox->addWidget(combo);
	hbox->addWidget(button);
	//---"Spin Box" & "Line Edit"---//
	QSpinBox* spinBox = new QSpinBox();
	spinBox->setRange(0,9);
	QLineEdit* lineEdit = new QLineEdit();
	lineEdit->setText("Hello world");

	//------"Group Box"------//
	QGroupBox* group = new QGroupBox();//'方块' 
	//------"Radio Button"------//
	QRadioButton* r1 = new QRadioButton("RadioButton-1",group);
	QRadioButton* r2 = new QRadioButton("RadioButton-2",group);
	QCheckBox* chk = new QCheckBox("CheckBox",group);
	QVBoxLayout* vbox = new QVBoxLayout();
	vbox->addWidget(r1);
	vbox->addWidget(r2);
	vbox->addWidget(chk);
	group->setLayout(vbox);

	//------left "Main" Layout------//
	QVBoxLayout* leftmain = new QVBoxLayout();
	leftmain->addLayout(hbox);
	leftmain->addWidget(spinBox);
	leftmain->addWidget(lineEdit);
	leftmain->addWidget(group);
	//Left Frame's Layout
	leftFrame->setLayout(leftmain);
	//connect
	connect(combo,SIGNAL(activated(QString)),
			this,SLOT(slotChangeStyle(QString)) );
	//set default style here
	slotChangeStyle(QStyleFactory::keys()[5]);
}

void style::right()
{
	rightFrame = new QFrame();
	rightFrame->setFrameStyle(QFrame::Panel|QFrame::Raised);

	//----"slider"----//
	QSlider* slider = new QSlider(Qt::Horizontal);
	//----"Table"----//
	QTableWidget* table = new QTableWidget();
	table->setColumnCount(3);//x "列"
	table->setRowCount(6);//y "行"
	//--Text "Edit"--//
	QTextEdit* edit=new QTextEdit();
	edit->setText("Text Edit Here\n");
	//------right "Main" Layout-------//
	QVBoxLayout* rightmain = new QVBoxLayout();
	rightmain->setSpacing(8);
	rightmain->addWidget(slider);
	rightmain->addWidget(table);
	rightmain->addWidget(edit);
	//Right Frame's Layout
	rightFrame->setLayout(rightmain);
}

void style::slotChangeStyle(QString style)
{
	QApplication::setStyle( QStyleFactory::create(style) );
	QApplication::setPalette( QApplication::style()->standardPalette() );
}

