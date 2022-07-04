# wsl2の問題点
* wsl2ではsystemctlが使えない。
    * 原因：PID1でsystemdが起動していないため、systemctlが使えない。

# 参考
* Ubuntuでsystemctlを利用する方法
    * https://snowsystem.net/other/windows/wsl2-ubuntu-systemctl/
    