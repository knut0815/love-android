/*
	dummy: dummy audio output

	copyright ?-2006 by the mpg123 project - free software under the terms of the LGPL 2.1
	see COPYING and AUTHORS files in distribution or http://mpg123.org
*/

#include "mpg123app.h"
#include "debug.h"

static int open_dummy(audio_output_t *ao)
{
	debug("open_dummy()");
	return 0;
}

static int get_formats_dummy(audio_output_t *ao)
{
	debug("get_formats_dummy()");
	return MPG123_ENC_SIGNED_16;
}

static int write_dummy(audio_output_t *ao,unsigned char *buf,int len)
{
	debug("write_dummy()");
	return len;
}

static void flush_dummy(audio_output_t *ao)
{
	debug("flush_dummy()");
}

static int close_dummy(audio_output_t *ao)
{
	debug("close_dummy()");
	return 0;
}

static int deinit_dummy(audio_output_t *ao)
{
	debug("deinit_dummy()");
	return 0;
}


static int init_dummy(audio_output_t* ao)
{
	if (ao==NULL) return -1;
	debug("init_dummy()");
	
	/* Set callbacks */
	ao->open = open_dummy;
	ao->flush = flush_dummy;
	ao->write = write_dummy;
	ao->get_formats = get_formats_dummy;
	ao->close = close_dummy;
	ao->deinit = deinit_dummy;

	/* Success */
	return 0;
}



/* 
	Module information data structure
*/
mpg123_module_t mpg123_output_module_info = {
	/* api_version */	MPG123_MODULE_API_VERSION,
	/* name */			"dummy",						
	/* description */	"Dummy audio output - does not output audio.",
	/* revision */		"$Rev:$",						
	/* handle */		NULL,
	
	/* init_output */	init_dummy,						
};

