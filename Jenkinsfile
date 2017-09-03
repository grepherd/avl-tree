pipeline {
    agent { dockerfile true }
    stages {
        stage('build') {
            steps {
                sh '/root/build.sh'
            }
        }
    }
}