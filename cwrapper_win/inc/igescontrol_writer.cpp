// Joseba Epalza, 2026, guardar como archivos IGES solo entidades 3D basicas.

#include <IGESControl_Writer.hxx>

#include <IGESCAFControl.hxx>
#include <IGESCAFControl_Writer.hxx>

#include <TopoDS_Compound.hxx>

#include <igescontrol_writer.h>


IGESControlWriter IGESControlWriter_Init() {
	IGESControl_Writer *ret = new IGESControl_Writer();
	IGESControl_Writer writer("MM");
	return (void *) ret;
}

void IGESControlWriter_Add(IGESControlWriter writer, TopoDSShape shape, IGESControlIgesModelType mode) {
	IGESControl_Writer *w = (IGESControl_Writer *) writer;
	TopoDS_Shape *s = (TopoDS_Shape *) shape;
	// variable 'mode' no empleada de momento, para el futuro
	printf("%d\n",mode);
	w->AddShape(*s);
}

int IGESControlWriter_Write(IGESControlWriter writer, const char *filename) {
	IGESControl_Writer *w = (IGESControl_Writer *) writer;
	return w->Write(filename);
}

void IGESControlWriter_Free(IGESControlWriter writer) {
	IGESControl_Writer *w = (IGESControl_Writer *) writer;
	delete w;
}