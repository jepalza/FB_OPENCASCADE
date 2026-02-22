dim as integer a,b,c,d,e,f
dim as string sa,sb,sc

dim as integer x,y
dim as integer w,h,nbut

nbut=46 'num botones desde el 0 (46 en este caso de 0 a 45)
h=24 ' medidas 24x24 

w=nbut*h


screenres w,600,32

for f=0 to nbut-1
	if f mod 2=0 then
		line(x,y)-step(h-1,h-1),&h1E90FF,bf
		draw string (x+5,y+10),str(f),rgb(255,255,255)
	else
		line(x,y)-step(h-1,h-1),&HFF901E,bf
		draw string (x+5,y+10),str(f),rgb(0,0,0)
	endif
	x+=h
next f

Dim As Any Ptr pImageBuffer = ImageCreate(nbut*h, h)

Get (0,0)-Step(w-1,h-1), pImageBuffer
'save image buffer to file
Dim As String fileName = "menubar.bmp"
BSave(fileName, pImageBuffer)
'free memory for image buffer
ImageDestroy(pImageBuffer)


sleep