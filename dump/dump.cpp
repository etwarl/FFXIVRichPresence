// dump.cpp: Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"
#include <string>

VOID StartProcess( LPCTSTR lpApplicationName )
{
   // additional information
   STARTUPINFO si;
   PROCESS_INFORMATION pi;

   // set the size of the structures
   ZeroMemory( &si, sizeof( si ) );
   si.cb = sizeof( si );
   ZeroMemory( &pi, sizeof( pi ) );

   // start the program up
   CreateProcess( lpApplicationName,   // the path
                  NULL,        // Command line
                  NULL,           // Process handle not inheritable
                  NULL,           // Thread handle not inheritable
                  FALSE,          // Set handle inheritance to FALSE
                  0,              // No creation flags
                  NULL,           // Use parent's environment block
                  NULL,           // Use parent's starting directory 
                  &si,            // Pointer to STARTUPINFO structure
                  &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
   );
   // Close process and thread handles. 
   CloseHandle( pi.hProcess );
   CloseHandle( pi.hThread );
}

extern "C" __declspec( dllexport ) const char * func( const char * in )
{
   StartProcess( L"RichPresence/FFXIVRichPresenceRunner.exe" );

   return "";
}

