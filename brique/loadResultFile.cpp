bool XOrthoLaserChantier::LoadResultFile(std::string resultsFolder)
{
	XErrorCommentaire(m_error,__FUNCTION__,"Chargement des Sifts inter-pano");
	XSystemInfo system;
	XPath p;
	std::vector<std::string> listResult;
	system.GetFileListInFolder(resultsFolder,listResult,"*.result");
	if(listResult.size() == 0)
		return XErrorError(m_error,__FUNCTION__,"Aucun fichier result dans le répertoire  ",resultsFolder.c_str());

	for(uint32 i=0; i< listResult.size(); i++)
		if(system.GetFileSize1(listResult[i].c_str()) > 0)
			AddSiftResult(listResult[i]);

	return true;
}
