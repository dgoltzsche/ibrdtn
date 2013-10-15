/*
 * ObservedFile.h
 *
 * Copyright (C) 2013 IBR, TU Braunschweig
 *
 * Written-by: David Goltzsche <goltzsch@ibr.cs.tu-bs.de>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *  Created on: Sep 23, 2013
 */
#include <vector>
#include <list>
#include <string>

#ifndef OBSERVEDFILE_H_
#define OBSERVEDFILE_H_

class ObservedFile
{
public:
	ObservedFile();
	virtual ~ObservedFile();

	virtual int getFiles(std::list<ObservedFile*>& files) = 0;
	virtual std::string getPath() = 0;
	virtual bool exists() = 0;
	virtual std::string getBasename() = 0;
	virtual size_t size() = 0;
	virtual bool isSystem() = 0;
	virtual bool isDirectory() = 0;

	virtual std::string getHash() = 0;

	void tick();
	void send();
	static bool hashcompare(ObservedFile* a, ObservedFile* b);
	static bool namecompare(ObservedFile* a, ObservedFile* b);
	static void setConfigImgPath(std::string path);
	static void setConfigRounds(size_t rounds);
	static void setConfigBadclock(bool badclock);

	bool lastHashesEqual( size_t n );
protected:
	std::vector<std::string> _hashes;
	size_t _last_sent;

	static std::string _conf_imgpath;
	static size_t _conf_rounds;
};



#endif /* OBSERVEDFILE_H_ */
