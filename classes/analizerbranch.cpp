#include "analizerbranch.h"

AnalizerBranch::AnalizerBranch(QList<std::string> Branch, bool &close, std::string & formulaOne, std::string  & formulaTwo)
{

    QList<std::string>::iterator itExternal = Branch.begin();
    QList<std::string>::iterator itInternal = Branch.begin();
    itInternal++;

    std::string input;
    bool closed = false;

    while(itExternal != Branch.end() && (closed == false))
    {
        //ACA ENTRARIA EN JUEGO LA INTERFAZ A LA QUE LE PASO EL STRING DE LA FORMULA QUE ESTOY COMPARANDO CON LAS DEMAS

        std::cout<<"Formula Actual: "<<*itExternal<<std::endl;
        std::cout<<"Cierra?";
        std::cin>>input;
        std::cout<<std::endl;
        if(input == "si")
        {
          closed = true;
          formulaOne = *itExternal;
          formulaTwo = "empty";
        }
        itInternal = itExternal;
        itInternal++;
        while(itInternal != Branch.end() && (closed == false))
        {
          std::cout<<"   "<<*itInternal<<"   "<<std::endl;
          std::cout<<"Cierra?  ";
          std::cin>>input;
          std::cout<<std::endl;

          if(input == "si")
          {
            closed = true;
            formulaOne = *itExternal;
            formulaTwo = *itInternal;
          }
          else
          {
              itInternal++;
          }

        }
        std::cout<<"**************************************"<<std::endl;
         itExternal++;

    }

   close = closed;

}

AnalizerBranch::~AnalizerBranch()
{

}

