#ifndef error_command_h
#define error_command_h

#include "command.h"

class ErrorCommand : public Command {

  public:
    ErrorCommand(CommandParser*);

    void updateBoard();
    void buildResponse();
};

#endif
