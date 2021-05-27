#include <glib.h>
#include <librsvg/rsvg.h>
#include <stdbool.h>
#include <stdint.h>
#include <signal.h>
#include <string.h>
#include <time.h>

#define SVGDIM_VERSION "1.0.0"

static void usage(void)
{
	fprintf(stderr,
			"svgdim %s\n"
			"\n"
			"Usage: svgdim <input.svg>\n"
			"  -h, --help              Output this help and exit\n"
			"  -V, --version           Output version and exit\n"
			"\n", SVGDIM_VERSION);
	exit(EXIT_FAILURE);
}

char * inputFilePath=0;

static void parse_options(int argc, char **argv)
{
	int i;

	for(i=1;i<argc;i++)
	{
		int lastarg = i==argc-1;

		if(!strcmp(argv[i],"-h") || !strcmp(argv[i], "--help"))
		{
			usage();
		}
		else if(!strcmp(argv[i],"-V") || !strcmp(argv[i], "--version"))
		{
			printf("svgdim %s\n", SVGDIM_VERSION);
			exit(EXIT_SUCCESS);
		}
		else
		{
			break;
		}
	}

	argc -= i;
	argv += i;

	if(argc<1)
		usage();

	inputFilePath = argv[0];
}

int main(int argc, char ** argv)
{
	GError * error=0;
	RsvgHandle * handle;
	RsvgDimensionData dim;

	parse_options(argc, argv);

	handle = rsvg_handle_new_from_file(inputFilePath, &error);
	if(handle==0 || error!=0)
		exit(EXIT_FAILURE);

	rsvg_handle_get_dimensions(handle, &dim);
	g_object_unref(handle);

	printf("%dx%d", dim.width, dim.height);
	
}
