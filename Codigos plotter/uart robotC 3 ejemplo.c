

char C;
int incomingChar; int i=0;
unsigned char Chars[13];
int Chars_Ascii[13];
int Cast_Numeros[13];
float X=0,Y=0,Z=0;

task main()
{
	// Setup the two UART ports
	configureSerialPort(uartOne, uartUserControl);
	setBaudRate(uartOne, baudRate9600);
	configureSerialPort(uartTwo, uartUserControl);
	setBaudRate(uartTwo, baudRate9600);
	//---------------------------------
	//while(1){
		while(i<13){
			sendChar(uartOne,'I');
			while(getChar(uartTwo) != -1){};
			while(true)
			{
				//sendChar(uartOne,'T');
				incomingChar = getChar(uartTwo);
				Chars_Ascii[i]=incomingChar;
				C = incomingChar;Chars[i]=C;
				if      (Chars_Ascii[i]==48){Cast_Numeros[i]=0;}
				else if (Chars_Ascii[i]==49){Cast_Numeros[i]=1;}
				else if (Chars_Ascii[i]==50){Cast_Numeros[i]=2;}
				else if (Chars_Ascii[i]==51){Cast_Numeros[i]=3;}
				else if (Chars_Ascii[i]==52){Cast_Numeros[i]=4;}
				else if (Chars_Ascii[i]==53){Cast_Numeros[i]=5;}
				else if (Chars_Ascii[i]==54){Cast_Numeros[i]=6;}
				else if (Chars_Ascii[i]==55){Cast_Numeros[i]=7;}
				else if (Chars_Ascii[i]==56){Cast_Numeros[i]=8;}
				else if (Chars_Ascii[i]==57){Cast_Numeros[i]=9;}
				if(incomingChar != -1){	i++;break;}
			}
		}
		i=0;

		X= (Cast_Numeros[0]*100)+
		(Cast_Numeros[1]*10)+
		(Cast_Numeros[2]*1)+
		(Cast_Numeros[3]*0.1)+
		(Cast_Numeros[4]*0.01)+
		(Cast_Numeros[5]*0.001);

		Y=
		(Cast_Numeros[6]*100)+
		(Cast_Numeros[7]*10)+
		(Cast_Numeros[8]*1)+
		(Cast_Numeros[9]*0.1)+
		(Cast_Numeros[10]*0.01)+
		(Cast_Numeros[11]*0.001);

		Z = Cast_Numeros[12];

		//sendChar(uartOne,'I');
//	}
	//---------------------------------
	//sendChar(uartOne,'R');
	//while(true){sendChar(uartOne,'W');wait1Msec(1000); }
}
