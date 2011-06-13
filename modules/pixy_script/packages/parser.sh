#!/bin/bash

echo "@ Exporting Pixy.pkg..."
tolua++ -n Pixy -o ../src/client/lua_Pixy.cpp Pixy.pkg

#echo "@ Exporting PixyInstance.pkg..."
tolua++ -n EServer -o lua_EServer.cpp EServer.pkg

#echo "@ Exporting CEGUI.pkg"
#tolua++ -n CEGUI -o ../src/lua_CEGUI.cpp CEGUI.pkg

echo "@ Done!"
