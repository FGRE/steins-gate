/* void CreateProcess(Handle, unk, unk, unk, Symbol) */

#include "nss/libtest.nss"

chapter main
{
    TestRequest();
    TestExecOrder();
    Exit();
}

function TestRequest()
{
    CreateColor("color", 1, 0, 0, 100, 100, "red");
    CreateProcess("proc1", 0, 0, 0, "Foo");
    WaitKey();
    Request("proc1", "Start");
    WaitKey();
    Request("proc1", "Pause");
    WaitKey();
    Request("proc1", "Resume");
    WaitKey();
    /* Deleting a process seems to delete all objects it created */
    Delete("proc1");
}

function Foo()
{
    /* However, identifiers do collide */
    CreateColor("color", 1, Center, Middle, 100, 100, "green");
    while (1)
    {
        Rotate("color", 2000, 0, 0, 360, null, true);
        Rotate("color", 2000, 0, 0, 0, null, true);
    }
}

function TestExecOrder()
{
    CreateProcess("proc2", 0, 0, 0, "Bar");
    $tm = Time();
    Request("proc2", "Start");
    /* Each thread gets a tick */
    while (Time() - $tm < 2)
    {
        Print("foo");
    }
    Delete("proc2");
}

function Bar()
{
    while (1)
    {
        Print("bar");
    }
}
