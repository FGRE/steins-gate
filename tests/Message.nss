#include "nss/libtest.nss"

chapter main
{
    PrintInt(Message("Title", "Text", YESNOCANCEL, QUESTION));
    PrintInt(Message("Title", "Text", YESNOCANCEL, INFORMATION));
    PrintInt(Message("Title", "Text", YESNOCANCEL, EXCLAMATION));
    PrintInt(Message("Title", "Text", OKCANCEL, STOP));
    PrintInt(Message("Title", "Text", ABORTRETRYIGNORE, QUESTION));
    PrintInt(Message("Title", "Text", ABORTRETRYIGNORE, QUESTION));
    PrintInt(Message("Title", "Text", ABORTRETRYIGNORE, QUESTION));
    PrintInt(Message("Title", "Text", RETRYCANCEL, QUESTION));
    PrintInt(Message("Title", "Text", RETRYCANCEL, QUESTION));
    WaitKey();
    Exit();
}

