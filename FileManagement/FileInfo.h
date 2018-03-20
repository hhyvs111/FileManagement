#pragma once
#ifndef FILEINFO_H_ 
#define FILEINFO_H_
#include "stdafx.h"

struct FileInfo
{
	int fileId;
	QString fileName;
	QString fileSize;
	QString fileType;
	QString fileTime;
	QString fileUser;
	int userId;
};
struct BreakFile
{
	qint64 recordId;
	int fileId;
	QString fileName;
	QString filePath;
	qint64 breakPoint;
};

inline QDataStream &operator>>(QDataStream &in, FileInfo &fileInfo)
{
	int fileId;
	QString fileName;
	QString fileSize;
	QString fileType;
	QString fileTime;
	QString fileUser;
	int userId;

	in >> fileId >> fileName >> fileSize
		>> fileTime >> fileType >> fileUser >> userId;


	fileInfo.fileId = fileId;
	fileInfo.fileName = fileName;
	fileInfo.fileSize = fileSize;
	fileInfo.fileType = fileType;
	fileInfo.fileTime = fileTime;
	fileInfo.fileUser = fileUser;
	fileInfo.userId = userId;

	return in;
}
#endif // !FILEINFO_H_
