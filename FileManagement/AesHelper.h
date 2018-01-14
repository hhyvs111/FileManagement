#ifndef AESHELPER_H
#define AESHELPER_H

#include <QString>
#include <QTextCodec>

#include <string.h>

#include "aes.h"

class AesHelper
{
public:
	AesHelper();
	~AesHelper();
	QString aesEncrypt(QString mingwen);

	QString aesUncrypt(QString miwen);

private:
	AES * aes;
};

#endif // AESHELPER_H