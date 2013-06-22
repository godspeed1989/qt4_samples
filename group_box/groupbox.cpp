#include"groupbox.h"

GroupBox::GroupBox( QWidget *parent, Qt::WindowFlags  f ) : QToolBox( parent, f )
{
	//////////////////*GroupBox1*///////////////////////
	QGroupBox *groupBox1 = new QGroupBox();

	toolButton1_1 = new QToolButton();
	toolButton1_1->setText( "beibei" );
	toolButton1_1->setIcon( QPixmap("1.png") );
	toolButton1_1->setIconSize( QPixmap("1.png").size() );
	toolButton1_1->setAutoRaise( true );//自动浮起,默认是失效的
	toolButton1_1->setToolButtonStyle( Qt::ToolButtonTextUnderIcon);//没这句只显示图象

	toolButton1_2 = new QToolButton();
	toolButton1_2->setText( "jingjing" );
	toolButton1_2->setIcon( QPixmap("1.png") );
	toolButton1_2->setIconSize( QPixmap("1.png").size() );
	toolButton1_2->setAutoRaise( true );
	toolButton1_2->setToolButtonStyle( Qt::ToolButtonTextBesideIcon );

	QVBoxLayout *layout1 = new QVBoxLayout();
	layout1->setMargin(10);
	layout1->setAlignment(Qt::AlignHCenter);
	layout1->addWidget(toolButton1_1);
	layout1->addWidget(toolButton1_2);
	layout1->addStretch();
	groupBox1->setLayout(layout1);

	///////////////////*GroupBox2*//////////////////////
	QGroupBox *groupBox2 = new QGroupBox();

	toolButton2_1 = new QToolButton();
	toolButton2_1->setText(  "pizicai" );
	toolButton2_1->setAutoRaise( TRUE );
	toolButton2_1->setToolButtonStyle( Qt::ToolButtonTextOnly);

	QVBoxLayout *layout2 = new QVBoxLayout();
	layout2->setMargin(10);
	layout2->setAlignment(Qt::AlignHCenter);
	layout2->addWidget(toolButton2_1);
	layout2->addStretch();
	groupBox2->setLayout(layout2);

	/////////////////*GroupBox3*///////////////////////
	QGroupBox *groupBox3 = new QGroupBox();

	toolButton3_1 = new QToolButton();
	toolButton3_1->setText( "QQ" );
	toolButton3_1->setIcon( QPixmap( "1.png" ) );
	toolButton3_1->setIconSize( QPixmap( "1.png").size() );
	toolButton3_1->setAutoRaise( TRUE );
	toolButton3_1->setToolButtonStyle( Qt::ToolButtonIconOnly);

	QVBoxLayout *layout3 = new QVBoxLayout();
	layout3->setMargin(10);
	layout3->setAlignment(Qt::AlignHCenter);
	layout3->addWidget(toolButton3_1);
	layout3->addStretch();
	groupBox3->setLayout(layout3);

	this->addItem( ( QWidget* )groupBox1 , "my friends");
	this->addItem( ( QWidget* )groupBox2 , "stranger");
	this->addItem( ( QWidget* )groupBox3 , "blacklist");
}

