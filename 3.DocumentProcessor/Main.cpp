#include <iostream>

#include "Document.h"
#include "DocumentProcessor.h"
#include "DocumentProcess.h"

#include "SpellcheckProcess.h"
#include "RepaginateProcess.h"
#include "TranslateIntoFrenchProcess.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// ���� ó���ڸ� �����ϴ� �Լ�.
DocumentProcessor* Configure()
{
	DocumentProcessor* processor = new DocumentProcessor();
	processor->AddDocumentProcess(DocumentProcess::TranslateIntoFrench);
	processor->AddDocumentProcess(DocumentProcess::SpellCheck);
	processor->AddDocumentProcess(DocumentProcess::Repaginate);

	//processor->GetProcesses().emplace_back(new TranslateIntoFrenchProcess());
	//processor->GetProcesses().emplace_back(new SpellcheckProcess());
	//processor->GetProcesses().emplace_back(new RepaginateProcess());

	return processor;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// ���� ��ü ����.
	Document doc1("Jake Oh", "2025.02.13", "C++ Programming");
	Document doc2("Ian Tim", "2024.01.31", "Hello Iphone");

	// ���� ó���� ��ü ���� (���丮 ����).
	DocumentProcessor* processor = Configure();

	// ���� ó��.
	std::cout << "����1 ó��\n";
	processor->Process(doc1);
	std::cout << "\n";

	std::cout << "����2 ó��\n";
	processor->Process(doc2);

	// �޸� ����.
	delete processor;
	std::cin.get();
}