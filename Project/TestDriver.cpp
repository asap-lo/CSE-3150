#include "ECProject.h"
#include "ECTextViewImp.h"

int main(int argc, char*argv[])
{
    ECTextViewImp viewImp;
    ECView view(&viewImp);
    ECModel model(&view);
    ECCommandHistory commandHistory;
    ECController controller(&model, &viewImp, &commandHistory);

    viewImp.AddStatusRow("Testing Features...", ":)", true);
    viewImp.Show();

    return 0;

}