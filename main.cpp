#include <iostream>
#include "IIfAllReader.h"
#include "IWhileReader.h"
#include "IForReader.h"

int main() {
    std::ifstream my_ifs(R"(I:\IDE\CLion\ICDecoder\input.txt)",std::ios_base::in);
    std::ofstream my_ofs(R"(I:\IDE\CLion\ICDecoder\output.txt)",std::ios_base::out);
    IIfAllReader iIfAllReader(&my_ifs, &my_ofs, 0);
    IWhileReader iWhileReader(&my_ifs, &my_ofs, 0);
    IForReader iForReader(&my_ifs, &my_ofs, 0);
    IBlockReader iBlockReader(&my_ifs, &my_ofs, 0);
    ISentenceReader iSentenceReader(&my_ifs, &my_ofs, 0);

    while(true)
    {
        if(iForReader.read());
        else if(iWhileReader.read());
        else if(iIfAllReader.read());
        else if(iBlockReader.read());
        else if(iSentenceReader.read());
        else break;
    }

    my_ifs.close();
    my_ofs.close();
    return 0;
}
