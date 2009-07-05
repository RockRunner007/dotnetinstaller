#pragma once

// UI level for installation

enum InstallUILevel
{
	InstallUILevelNotSet = 0, // not set
	InstallUILevelFull, // full UI mode
	InstallUILevelBasic, // basic UI mode
    InstallUILevelSilent // silent UI mode
};

class InstallUILevelSetting
{
public:
	InstallUILevelSetting();
	void SetConfigLevel(InstallUILevel value);
	void SetRuntimeLevel(InstallUILevel value);
	bool IsSilent() const; // true if running in any of the silent modes (basic or silent)
	bool IsAnyUI() const; // true if any UI level
	InstallUILevel GetUILevel(InstallUILevel defaultValue = InstallUILevelFull) const; // current combined UI level
	static InstallUILevel ToUILevel(const CString& pszLevel, InstallUILevel defaultValue = InstallUILevelNotSet);
private:
	InstallUILevel m_ConfigLevel;
	InstallUILevel m_RuntimeLevel;
};

extern InstallUILevelSetting CurrentInstallUILevel;