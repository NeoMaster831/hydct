#pragma once

#include "global.h"

namespace Ioctl {

	/*
		* @brief Initialize the Ioctl module.
		* @details You should first register
		*/
	bool Init();

	/*
		* @brief Send a request to the driver.
		* @param Request The request to send.
		* @param InputBuffer The input buffer.
		* @param InputBufferLength The input buffer length.
		* @param OutputBuffer The output buffer.
		* @param OutputBufferLength The output buffer length.
		* @return The status of the request.
		*/
	bool Request(
		DWORD Request,
		PVOID InputBuffer,
		DWORD InputBufferLength,
		PVOID OutputBuffer,
		DWORD OutputBufferLength
	);

	/*
		* @brief Close the Ioctl module.
		*/
	void Terminate();

}