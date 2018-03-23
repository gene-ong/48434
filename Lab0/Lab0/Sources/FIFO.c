/*
 * FIFO.c
 *
 *  Created on: 21 Mar 2018
 *      Author: 10607176
 */
#define bufferSize 10

//private global array
uint16_t BufferArray[bufferSize];
uint8_t WriteIndex = 0;
uint8_t ReadIndex = 0;

//variable to keep track of how much data is in the buffer array
uint8_t DataIndex = 0;

uint8_t FIFO_Write(uint16_t dataIn)
{
  //check to see if there is space available
  if(DataIndex<bufferSize)
    {
      BufferArray[WriteIndex]=dataIn;
      //increment WriteIndex
      WriteIndex++;
      DataIndex++;
    }

  //return error if no space available
  else if(DataIndex>=bufferSize)
    return(1);	//return 1 if there is an no space available


  //check if I've reached the end, if so go back to zero
  if(WriteIndex>=bufferSize)
    {
    WriteIndex = 0;
    }
}

uint16_t FIFO_Read(uint16_t *dataOut)
{

  //check to see if there is data available
  if(DataIndex>0)
    {
      *dataOut = BufferArray[ReadIndex];
      ReadIndex++;
      DataIndex--;
    }

  //return error if no data available
  else if(DataIndex==0)
    return(1);	//return 1 if there is an no data available


  //check if I've reached the end, if so go back to zero
  if(ReadIndex>=bufferSize)
      ReadIndex = 0;

  }
