#include "main_cpp.h"

Potentiometers	Pots;
Toggle_Switch		Tgl_Switch( _PC14_, _PC15_, false );

void Audio_Input_Callback( int v )
{
/*	int	pot_0 = Pots[ 0 ].Get_Value();

	int	tglsw = Tgl_Switch.Get_Value();

	     if( tglsw == TGLSW::Pin_0 ){}
  else if( tglsw == TGLSW::Pin_1 ){}
  else if( tglsw == TGLSW::Pin_OFF ){}
*/
	Audio::Set_Output( v );
}

extern "C" void main_cpp()
{
	Pots.Start();

	Audio::Start();

	Audio::Active();

	while( 1 )
	{
		HAL_Delay( 10 );

		Pots.Update();

		HAL_Delay( 10 );

		Tgl_Switch.Update();
	}
}
