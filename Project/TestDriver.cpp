#include "ECProject.h"
#include "ECTextViewImp.h"

int main(int argc, char*argv[])
{
    ECTextViewImp viewImp;
    ECView view(&viewImp);
    ECModel model(&view);
    ECController controller(&model, &viewImp);

    viewImp.AddStatusRow("Testing Features...", ":)", true);
    viewImp.Show();

    return 0;

}