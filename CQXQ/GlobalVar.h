#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <vector>
#include <string>
#include <atomic>
#include <map>

extern HMODULE hDllModule;

struct eventType
{
	int plugin_id = -1;
	int priority = 30000;
	FARPROC event = nullptr;
	bool operator<(const eventType& that) const
	{
		return this->priority < that.priority;
	}
};

struct native_plugin
{
	int id;
	std::string file;
	std::string name;
	std::string version;
	int version_id;
	std::string author;
	std::string description;
	std::map<int, eventType> events;
	std::vector<std::pair<std::string, FARPROC>> menus;
	HMODULE dll;
	bool enabled;

	native_plugin(int i, const std::string& f)
	{
		id = i;
		file = f;
		dll = nullptr;
		enabled = true;
	}
};

// �洢���в��
extern std::vector<native_plugin> plugins;

// �洢���������в���¼�
extern std::map<int, std::vector<eventType>> plugins_events;

// XQ��Ŀ¼, ��β����б��
extern std::string rootPath;

// �����¼��Ƿ��Ѿ������ã�������QQ��½�ɹ��Ժ��ٵ��������¼�
extern bool EnabledEventCalled;

// �Ƿ���������Լ����¼�
extern bool RecvSelfEvent;

// �Ƿ�������
extern std::atomic<bool> running;
