#include "GlobalVar.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <vector>
#include <string>
#include <map>

HMODULE hDllModule;

// ���в��
std::vector<native_plugin> plugins;

// ���������в���¼�
std::map<int, std::vector<eventType>> plugins_events;

// XQ��Ŀ¼, ��β����б��
std::string rootPath;

// �����¼��Ƿ��Ѿ������ã�������QQ��½�ɹ��Ժ��ٵ��������¼�
bool EnabledEventCalled = false;

// �Ƿ���������Լ����¼�
bool RecvSelfEvent = false;