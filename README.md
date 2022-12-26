# -OK-
Based on QT graphics framework (including network and mysql modules)

Client: Based on QT5.9.0, mingw32 compiler
Server-side: Based on QT5.9 mscv64 for 2017 compiler

School software engineering homework, software rushed out in three and a half days, some deficiencies.
1. The server's socket can only accept the latest socket, which means that after a new client connection, the server no longer retains the old socket link. QList can be used<QTcpSocket>,
  Further improve the client class structure and communication format (add ID information) to improve.
2. About interface switching.
  Some big guys said that you can use QStackedWidget to achieve fluent interface switching, but due to the time limit, there is no in-depth learning, and the specific effect is not very clear, and we will discuss it later (there is probably no next time when you say this sentence)
