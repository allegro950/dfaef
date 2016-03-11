#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtCore/QString>
#include <QtCore/QTextCodec>

QString qkor(const char *strKor)
{
	static QTextCodec *codec = QTextCodec::codecForName("eucKR");
	return codec->toUnicode(strKor);
}

const QString qsButtNormal = qkor("¥≠∑Ø¡‡");

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QPushButton hello;
	hello.setText(qsButtNormal);
	QObject::connect(&hello, SIGNAL(clicked()), &app, SLOT(quit()));
	hello.show();
	return app.exec();
}