#include "ECProject.h"
#include "ECTextViewImp.h"

int main(int argc, char*argv[])
{
    ECTextViewImp viewImp;
    ECView view(&viewImp);
    ECModel model(&view, string(argv[1]));
    ECCommandHistory commandHistory;
    ECController controller(&model, &viewImp, &commandHistory);

    viewImp.AddStatusRow("****COMMAND MODE****", "Press i for insert mode", true);
    viewImp.Show();

    return 0;

}