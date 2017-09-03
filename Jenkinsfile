pipeline {
    agent { dockerfile true }
    stages {
        stage('build') {
            steps {
                sh './build.sh'
            }
        }
        stage('test') {
            steps {
                sh './build/bin/tests'
            }
        }
    }
}