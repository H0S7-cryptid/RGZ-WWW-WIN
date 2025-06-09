#include "LR_list.h"
#include "FILE_FUNC.h"

void CreateAndOrWriteTV(const char* file_name, node** head) {
	int descriptor = 0;

	errno_t err = _sopen_s(&descriptor, file_name, _O_WRONLY | _O_CREAT, _SH_DENYNO, S_IWRITE);
	if (err != 0) {
		perror("Error when opening a file!");
		return;
	}

	node* temp = *head;
	int bytes_written = 0;
	while (temp != NULL) {
		bytes_written += _write(descriptor, &temp->data, sizeof(TV));
		temp = temp->next;
	}

	_close(descriptor);
}

void GetTVFromFile(const char* file_name, node** head) {
	int descriptor = 0;

	errno_t err = _sopen_s(&descriptor, file_name, _O_RDONLY | _O_CREAT, _SH_DENYNO, S_IREAD);
	if (err != 0) {
		perror("Error when opening a file!");
		return;
	}

	off_t size = _lseek(descriptor, 0, SEEK_END);
	_lseek(descriptor, 0, SEEK_SET);

	TV buffer;
	int bytes_read = 0;
	while (bytes_read != size) {
		bytes_read += _read(descriptor, &buffer, sizeof(buffer));
		*head = Insert(*head, buffer);
	}

	_close(descriptor);
}
